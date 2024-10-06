---
editor_options: 
  markdown: 
    wrap: 72
---

# RcppPerfCalc

`RcppPerfCalc` is an R package that provides high-performance financial
calculation functions by utilizing C++ via the `Rcpp` and
`RcppArmadillo` libraries. The package offers several key metrics, such
as annualized return, annualized risk (standard deviation), annualized
downside deviation, and maximum drawdown. These functions are
implemented in C++ to significantly improve computational speed compared
to their counterparts in the `PerformanceAnalytics` package.

# Features

-   **Annualized Return**: Efficiently computes the annualized return
    for a series of returns.
-   **Annualized Risk**: Calculates the annualized standard deviation
    (risk) of returns, offering faster performance.
-   **Annualized Downside Deviation**: Computes the downside risk of a
    return series, based on deviations below a certain threshold.
-   **Maximum Drawdown (MDD)**: Quickly calculates the maximum observed
    loss from a peak to a trough in a return series.

This package is ideal for users who need to process large financial
datasets quickly and require efficient performance for real-time or
large-scale applications.

------------------------------------------------------------------------

# Performance benchmarking

We conducted a performance benchmarking to compare the execution speed
of the functions implemented in the `RcppPerfCalc` package against their
counterparts in the `PerformanceAnalytics` library. The goal was to
confirm that the Rcpp implementations provide significant improvements
in computational efficiency, especially for large datasets.

We generated normally distributed return data with 6,000 data points
(daily returns) and measured execution times using the `microbenchmark`
library, running each test 10 times.

``` r
x = rnorm(6000, 0.01, 0.01)
```

In summary, the Rcpp implementations consistently outperformed the R
versions, especially for large datasets, confirming the benefits of C++
optimization

## Benchmark Results Interpretation

The benchmark results compare the C++ (`cpp`) implementations in the
`RcppPerfCalc` package with their R counterparts(`r`) in the
`PerformanceAnalytics` library. Each result is measured in microseconds
(µs). In all cases, the `cpp` implementations demonstrated significantly
better performance compared to the R versions, particularly with large
datasets.

For example, the `annualized_return` function in C++ (`cpp`) shows a
minimum execution time of 7.4 µs, while the R equivalent(`r`) takes
296.5 µs, showcasing a substantial improvement in speed. Similar trends
are observed for all other functions, where `RcppPerfCalc` provides
faster computation due to C++ optimizations.

------------------------------------------------------------------------

## Annualized Return

The `annualized_return` function calculates the annualized return for a
series of returns, compared here against
`PerformanceAnalytics::Return.annualized`.

``` r
benchmark <- microbenchmark(
  cpp = {RcppPerfCalc::annualized_return(x, 252)},
  r   = {PerformanceAnalytics::Return.annualized(x, scale=252)},
  times = 10
)
benchmark

# Benchmark Results:
# 
# Unit: microseconds
#  expr   min    lq   mean median    uq   max neval cld
#   cpp   7.4   7.5  12.68   7.65  17.9  36.8    10  a 
#     r 296.5 297.9 362.68 309.05 344.7 641.1    10   b
```

## Annualized Risk

The `annualized_sd` function calculates the annualized standard
deviation (risk), compared here against
`PerformanceAnalytics::sd.annualized`.

``` r
benchmark <- microbenchmark(
  cpp = {RcppPerfCalc::annualized_sd(x, 252)},
  r   = {PerformanceAnalytics::sd.annualized(x, 252)},
  times = 10
)
benchmark

# Benchmark Results:
# 
# Unit: microseconds
#  expr  min   lq  mean median   uq  max neval cld
#   cpp 11.1 11.1 14.25  11.65 13.2 36.5    10  a 
#     r 20.2 21.4 25.11  22.05 23.0 53.4    10   b
```

## Annualized Downside Deviation (DD)

The `annualized_dd` function calculates the annualized downside
deviation, compared here against
`PerformanceAnalytics::DownsideDeviation`.

``` r
benchmark <- microbenchmark(
  cpp = {RcppPerfCalc::annualized_dd(x, 252)},
  r   = {
     PerformanceAnalytics::DownsideDeviation(x, MAR = 0.0)[1,1]
    },
  times = 10
)
benchmark

# Benchmark Results:
# 
# Unit: microseconds
#  expr  min   lq  mean median   uq   max neval cld
#   cpp 15.4 17.8 25.21  21.50 24.2  68.6    10  a 
#     r 39.2 43.4 54.55  48.45 53.2 115.5    10   b
```

### Maximum Drawdown (MDD)

The `mdd` function computes the maximum drawdown, compared here against
`PerformanceAnalytics::maxDrawdown`.

``` r
benchmark <- microbenchmark(
  cpp = {RcppPerfCalc::mdd(x)},
  r   = {
    l = length(x)
    dummy_dates = seq(as.Date("2000-01-31"), length = l, by = "day")
    R = xts::xts(x = x, order.by = dummy_dates)
    PerformanceAnalytics::maxDrawdown(R, invert = FALSE)
  },
  times = 10
)
benchmark

# Benchmark Results:
# 
# Unit: microseconds
#  expr   min    lq   mean median    uq   max neval cld
#   cpp   7.7   7.8  13.22   14.6  16.3  20.6    10  a 
#     r 592.6 605.4 656.81  622.0 668.0 924.0    10   b
```

# License

This package is licensed under the MIT License. You are free to use,
modify, and distribute the package under the terms of the license. See
the LICENSE file for more details.
