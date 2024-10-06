// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// annualized_return
double annualized_return(const std::vector<double>& returns, int period_per_year);
RcppExport SEXP _RcppPerfCalc_annualized_return(SEXP returnsSEXP, SEXP period_per_yearSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type returns(returnsSEXP);
    Rcpp::traits::input_parameter< int >::type period_per_year(period_per_yearSEXP);
    rcpp_result_gen = Rcpp::wrap(annualized_return(returns, period_per_year));
    return rcpp_result_gen;
END_RCPP
}
// annualized_sd
double annualized_sd(NumericVector x, int scale);
RcppExport SEXP _RcppPerfCalc_annualized_sd(SEXP xSEXP, SEXP scaleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< int >::type scale(scaleSEXP);
    rcpp_result_gen = Rcpp::wrap(annualized_sd(x, scale));
    return rcpp_result_gen;
END_RCPP
}
// annualized_dd
double annualized_dd(const std::vector<double>& returns, int period_per_year);
RcppExport SEXP _RcppPerfCalc_annualized_dd(SEXP returnsSEXP, SEXP period_per_yearSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const std::vector<double>& >::type returns(returnsSEXP);
    Rcpp::traits::input_parameter< int >::type period_per_year(period_per_yearSEXP);
    rcpp_result_gen = Rcpp::wrap(annualized_dd(returns, period_per_year));
    return rcpp_result_gen;
END_RCPP
}
// mdd
double mdd(NumericVector returns);
RcppExport SEXP _RcppPerfCalc_mdd(SEXP returnsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type returns(returnsSEXP);
    rcpp_result_gen = Rcpp::wrap(mdd(returns));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_RcppPerfCalc_annualized_return", (DL_FUNC) &_RcppPerfCalc_annualized_return, 2},
    {"_RcppPerfCalc_annualized_sd", (DL_FUNC) &_RcppPerfCalc_annualized_sd, 2},
    {"_RcppPerfCalc_annualized_dd", (DL_FUNC) &_RcppPerfCalc_annualized_dd, 2},
    {"_RcppPerfCalc_mdd", (DL_FUNC) &_RcppPerfCalc_mdd, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_RcppPerfCalc(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
