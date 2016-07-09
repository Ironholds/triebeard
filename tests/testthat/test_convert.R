testthat::context("Test conversion of tries into other R objects")

testthat::test_that("Tries can be turned into lists", {
  trie_inst <- trie("foo", "bar")
  trlist <- as.list(trie_inst)
  testthat::expect_true(is.list(trlist))
  testthat::expect_equal(length(trlist), 2)
  testthat::expect_equal(names(trlist), c("keys", "values"))
  testthat::expect_equal(trlist$values, "bar")
  testthat::expect_equal(trlist$keys, "foo")
})

testthat::test_that("Tries can be turned into lists", {
  trie_inst <- trie("foo", "bar")
  trlist <- as.data.frame(trie_inst)
  testthat::expect_true(is.data.frame(trlist))
  testthat::expect_equal(ncol(trlist), 2)
  testthat::expect_equal(names(trlist), c("keys", "values"))
  testthat::expect_equal(trlist$values, "bar")
  testthat::expect_equal(trlist$keys, "foo")
})