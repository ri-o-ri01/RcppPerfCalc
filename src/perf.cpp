#include <RcppArmadillo.h>
// Rcpp.hはRcppArmadillo.hに含まれているため、個別に含める必要はありません

// RcppArmadilloを使用する際の標準的な宣言
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;


// [[Rcpp::export]]
double annualized_return(const std::vector<double>& returns, int period_per_year) {
  double compounded_return = std::accumulate(returns.begin(), returns.end(), 1.0,
                                             [](double acc, double r) { return acc * (1 + r); });
  int n = returns.size();
  return std::pow(compounded_return, period_per_year / static_cast<double>(n)) - 1;
}

// [[Rcpp::export]]
double annualized_sd(NumericVector x, int scale) {
  // NA 値を除外
  x = na_omit(x);
  int n = x.size();

  // 平均を計算
  double mean = std::accumulate(x.begin(), x.end(), 0.0) / n;

  // 分散を計算
  double variance = std::accumulate(x.begin(), x.end(), 0.0, [mean](double acc, double val) {
    return acc + (val - mean) * (val - mean);
  }) / (n - 1);

  // 標準偏差を計算し、年率化
  return std::sqrt(variance * scale);
}


// [[Rcpp::export]]
double annualized_dd(const std::vector<double>& returns, int period_per_year) {
  double MAR = 0.0;
  std::vector<double> downside_diffs;

  std::transform(returns.begin(), returns.end(), std::back_inserter(downside_diffs),
                 [MAR](double r) { return r < MAR ? MAR - r : 0; });

  double sum_sq = std::inner_product(downside_diffs.begin(), downside_diffs.end(), downside_diffs.begin(), 0.0);
  double downside_variance = sum_sq / downside_diffs.size();

  return std::sqrt(downside_variance) * std::sqrt(period_per_year);
}
// [[Rcpp::export]]
double mdd(NumericVector returns) {
  double maxDD = 0.0;
  double peak = 1.0;  // 初期資産価値は1とする
  double trough = 1.0;  // 初期のトラフも1とする

  for (int i = 0; i < returns.size(); i++) {
    trough *= (1 + returns[i]);  // 累積資産価値（トラフ）を更新

    if (trough > peak) {
      peak = trough;  // 新しいピークを設定
    }

    double DD = (peak - trough) / peak;  // ピークからのドローダウンを計算
    if (DD > maxDD) {
      maxDD = DD;  // 最大ドローダウンを更新
    }
  }

  return maxDD * -1;  // 最大ドローダウンを返す
}
