context("Test trie creation")

testthat::test_that("String tries can be created and safely avoid collection", {
  string_trie <- trie(LETTERS, LETTERS)
  testthat::expect_true(any(class(string_trie) == "string_trie"))
  testthat::expect_true(any(class(string_trie) == "trie"))
})

testthat::test_that("Integer tries can be created", {
  int_trie <- trie(LETTERS, 1:length(LETTERS))

  testthat::expect_true(any(class(int_trie) == "integer_trie"))
  testthat::expect_true(any(class(int_trie) == "trie"))
})

testthat::test_that("Double tries can be created", {
  vals <- as.double(1:length(LETTERS))
  double_trie <- trie(LETTERS, vals)

  testthat::expect_true(any(class(double_trie) == "numeric_trie"))
  testthat::expect_true(any(class(double_trie) == "trie"))
})

testthat::test_that("Logical tries can be created", {
  vals <- as.logical(rep(c(0,1), (length(LETTERS)/2)))
  bool_trie <- trie(LETTERS, vals)

  testthat::expect_true(any(class(bool_trie) == "logical_trie"))
  testthat::expect_true(any(class(bool_trie) == "trie"))
})
