context("Test key and value retrieval")

testthat::test_that("String keys and values can be retrieved", {
  string_trie <- trie(LETTERS, LETTERS)
  testthat::expect_equal(LETTERS, get_values(string_trie))
  testthat::expect_equal(LETTERS, get_keys(string_trie))
})

testthat::test_that("Integer keys and values can be retrieved", {
  int_trie <- trie(LETTERS, 1:length(LETTERS))
  testthat::expect_equal(1:length(LETTERS), get_values(int_trie))
  testthat::expect_equal(LETTERS, get_keys(int_trie))
})

testthat::test_that("Numeric keys and values can be retrieved", {
  vals <- as.double(1:length(LETTERS))
  double_trie <- trie(LETTERS, vals)

  testthat::expect_equal(vals, get_values(double_trie))
  testthat::expect_equal(LETTERS, get_keys(double_trie))
})

testthat::test_that("Boolean keys and values can be retrieved", {
  vals <- as.logical(rep(c(0,1), (length(LETTERS)/2)))
  bool_trie <- trie(LETTERS, vals)

  testthat::expect_equal(vals, get_values(bool_trie))
  testthat::expect_equal(LETTERS, get_keys(bool_trie))
})