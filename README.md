##triebeard

Fast key-value matching in R and Rcpp

__Author:__ Oliver Keyes, Drew Schmidt, Yuuki Takano<br/>
__License:__ [MIT](http://opensource.org/licenses/MIT)<br/>
__Status:__ Stable

[![Travis-CI Build Status](https://travis-ci.org/Ironholds/triebeard.svg?branch=master)](https://travis-ci.org/Ironholds/triebeard) ![downloads](http://cranlogs.r-pkg.org/badges/grand-total/triebeard)

###Description

Tries, or [radix trees](https://en.wikipedia.org/wiki/Radix_tree), are key-value data structures optimised
for matching. Or to put it another way, if you have a pile of labels that match to particular values, and you want to take label-based data and extract the equivalent value(s) for each entry, you can handle three million entries in a second.

This is pretty useful in data cleaning and value extraction, and tries let you do it *really* efficiently. `triebeard` contains
an implementation that can be used both when writing R, and when writing Rcpp (and imported and linked against, to boot). For more information see:

1. The [vignette on Rcpp usage](https://github.com/Ironholds/triebeard/blob/master/vignettes/rcpp_radix.Rmd);
2. The [vignette on R usage](https://github.com/Ironholds/triebeard/blob/master/vignettes/r_radix.Rmd).

Please note that this project is released with a [Contributor Code of Conduct](CONDUCT.md).
By participating in this project you agree to abide by its terms.

###Installation

The stable, CRAN-ready version can be retrieved with:

    install.packages("triebeard")

The latest version can be obtained via:

    devtools::install_github("ironholds/triebeard")

###Dependencies
* R.
* [Rcpp](https://cran.r-project.org/package=Rcpp)