context("Test trie creation")

testthat::test_that("String tries can be created and safely avoid collection", {
  string_trie <- create_trie(LETTERS, LETTERS)

  testthat::expect_true(any(class(string_trie) == "string_trie"))
  testthat::expect_true(any(class(string_trie) == "trie"))
  testthat::expect_equal(LETTERS, get_values(string_trie))
  testthat::expect_equal(LETTERS, get_keys(string_trie))
})

testthat::test_that("Integer tries can be created", {
  int_trie <- create_trie(LETTERS, 1:length(LETTERS))

  testthat::expect_true(any(class(int_trie) == "integer_trie"))
  testthat::expect_true(any(class(int_trie) == "trie"))
  testthat::expect_equal(1:length(LETTERS), get_values(int_trie))
  testthat::expect_equal(LETTERS, get_keys(int_trie))

})

testthat::test_that("Double tries can be created", {
  vals <- as.double(1:length(LETTERS))
  double_trie <- create_trie(LETTERS, vals)

  testthat::expect_true(any(class(double_trie) == "numeric_trie"))
  testthat::expect_true(any(class(double_trie) == "trie"))
  testthat::expect_equal(vals, get_values(double_trie))
  testthat::expect_equal(LETTERS, get_keys(double_trie))
})

testthat::test_that("Logical tries can be created", {
  vals <- as.logical(rep(c(0,1), (length(LETTERS)/2)))
  bool_trie <- create_trie(LETTERS, vals)

  testthat::expect_true(any(class(bool_trie) == "logical_trie"))
  testthat::expect_true(any(class(bool_trie) == "trie"))
  testthat::expect_equal(vals, get_values(bool_trie))
  testthat::expect_equal(LETTERS, get_keys(bool_trie))
})
