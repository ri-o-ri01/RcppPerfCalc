
test_that("annualized_return", {

  # Test Case 1: Normal case with mixed returns
  input = c(0.01, 0.02, 0.015, -0.02, 0.03)
  e_ar = PerformanceAnalytics::Return.annualized(input, scale=252)
  a_ar = RcppPerfCalc::annualized_return(input, 252)
  expect_equal(a_ar, e_ar, tolerance = 1e-8)

  # Test Case 2: All positive returns
  input = c(0.02, 0.03, 0.015, 0.01, 0.025)
  e_ar = PerformanceAnalytics::Return.annualized(input, scale=252)
  a_ar = RcppPerfCalc::annualized_return(input, 252)
  expect_equal(a_ar, e_ar, tolerance = 1e-8)

  # Test Case 3: All negative returns
  input = c(-0.02, -0.01, -0.03, -0.015, -0.025)
  e_ar = PerformanceAnalytics::Return.annualized(input, scale=252)
  a_ar = RcppPerfCalc::annualized_return(input, 252)
  expect_equal(a_ar, e_ar, tolerance = 1e-8)

  # Test Case 4: Mixed returns with weekly scale (scale=52)
  input = c(0.01, -0.02, 0.015, 0.03, -0.01)
  e_ar = PerformanceAnalytics::Return.annualized(input, scale=52)
  a_ar = RcppPerfCalc::annualized_return(input, 52)
  expect_equal(a_ar, e_ar, tolerance = 1e-8)

  # Test Case 5: Zero returns
  input = c(0, 0, 0, 0, 0)
  e_ar = PerformanceAnalytics::Return.annualized(input, scale=252)
  a_ar = RcppPerfCalc::annualized_return(input, 252)
  expect_equal(a_ar, e_ar, tolerance = 1e-8)

})

test_that("annualized_sd", {

  # Test Case 1: Normal case with mixed returns
  input = c(0.01, 0.02, 0.015, -0.02, 0.03)
  expected = PerformanceAnalytics::sd.annualized(input, scale=252)
  actual = RcppPerfCalc::annualized_sd(input, 252)
  expect_equal(actual, expected, tolerance = 1e-8)

  # Test Case 2: All positive returns
  input = c(0.02, 0.03, 0.015, 0.01, 0.025)
  expected = PerformanceAnalytics::sd.annualized(input, scale=252)
  actual = RcppPerfCalc::annualized_sd(input, 252)
  expect_equal(actual, expected, tolerance = 1e-8)

  # Test Case 3: All negative returns
  input = c(-0.02, -0.01, -0.03, -0.015, -0.025)
  expected = PerformanceAnalytics::sd.annualized(input, scale=252)
  actual = RcppPerfCalc::annualized_sd(input, 252)
  expect_equal(actual, expected, tolerance = 1e-8)

  # Test Case 4: Mixed returns with weekly scale (scale=52)
  input = c(0.01, -0.02, 0.015, 0.03, -0.01)
  expected = PerformanceAnalytics::sd.annualized(input, scale=52)
  actual = RcppPerfCalc::annualized_sd(input, 52)
  expect_equal(actual, expected, tolerance = 1e-8)

  # Test Case 5: Zero returns
  input = c(0, 0, 0, 0, 0)
  expected = PerformanceAnalytics::sd.annualized(input, scale=252)
  actual = RcppPerfCalc::annualized_sd(input, 252)
  expect_equal(actual, expected, tolerance = 1e-8)

})

test_that("annualized_dd", {

  # Test Case 1: Mixed returns with MAR = 0
  input = c(0.01, 0.02, 0.015, -0.02, 0.03)
  expected = PerformanceAnalytics::DownsideDeviation(input, MAR = 0.0)[1,1] * sqrt(252)
  actual = RcppPerfCalc::annualized_dd(input, 252)
  expect_equal(actual, expected, tolerance = 1e-8)

  # Test Case 2: All positive returns with MAR = 0
  input = c(0.02, 0.03, 0.015, 0.01, 0.025)
  expected = PerformanceAnalytics::DownsideDeviation(input, MAR = 0.0)[1,1] * sqrt(252)
  actual = RcppPerfCalc::annualized_dd(input, 252)
  expect_equal(actual, expected, tolerance = 1e-8)

  # Test Case 3: All negative returns with MAR = 0
  input = c(-0.02, -0.01, -0.03, -0.015, -0.025)
  expected = PerformanceAnalytics::DownsideDeviation(input, MAR = 0.0)[1,1] * sqrt(252)
  actual = RcppPerfCalc::annualized_dd(input, 252)
  expect_equal(actual, expected, tolerance = 1e-8)

  # Test Case 4: Mixed returns with weekly scale (scale = 52)
  input = c(0.01, -0.02, 0.015, 0.03, -0.01)
  expected = PerformanceAnalytics::DownsideDeviation(input, MAR = 0.0)[1,1] * sqrt(52)
  actual = RcppPerfCalc::annualized_dd(input, 52)
  expect_equal(actual, expected, tolerance = 1e-8)

})

test_that("mdd", {


  # Test Case 1: Small drawdown followed by recovery
  input = c(-0.01, 0.02, 0.015, -0.02, 0.03)
  expected = -0.02
  actual = RcppPerfCalc::mdd(input)
  expect_equal(actual, expected, tolerance = 1e-8)
  # Test Case 2: Large initial drop followed by partial recovery
  input = c(-0.15, 0.01, -0.02, 0.02, 0.03)
  expected = -0.15867
  actual = RcppPerfCalc::mdd(input)
  expect_equal(actual, expected, tolerance = 1e-8)
  # Test Case 3: No drawdown (only positive returns)
  input = c(0.15, 0.01, 0.02, 0.02, 0.03)
  expected = 0.0
  actual = RcppPerfCalc::mdd(input)
  expect_equal(actual, expected, tolerance = 1e-8)
})







