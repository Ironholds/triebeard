context("Test trie alteration")

testthat::test_that("String tries can be altered", {
  trie <- create_trie("foo", "bar")
  original_length <- length(trie)
  trie_add(trie, "baz", "qux")
  increased_length <- length(trie)
  trie_remove(trie, "baz")

  testthat::expect_true(original_length < increased_length)
  testthat::expect_true(length(trie) == original_length)
})

testthat::test_that("String tries can be altered", {
  trie <- create_trie("foo", "bar")
  original_length <- length(trie)
  trie_add(trie, "baz", "qux")
  increased_length <- length(trie)
  trie_remove(trie, "baz")

  testthat::expect_true(original_length < increased_length)
  testthat::expect_true(length(trie) == original_length)
})


testthat::test_that("Integer tries can be altered", {
  trie <- create_trie("foo", 1)
  original_length <- length(trie)
  trie_add(trie, "baz", 2)
  increased_length <- length(trie)
  trie_remove(trie, "baz")

  testthat::expect_true(original_length < increased_length)
  testthat::expect_true(length(trie) == original_length)
})


testthat::test_that("Numeric tries can be altered", {
  trie <- create_trie("foo", as.numeric(1))
  original_length <- length(trie)
  trie_add(trie, "baz", as.numeric(2))
  increased_length <- length(trie)
  trie_remove(trie, "baz")

  testthat::expect_true(original_length < increased_length)
  testthat::expect_true(length(trie) == original_length)
})

testthat::test_that("Logical tries can be altered", {
  trie <- create_trie("foo", FALSE)
  original_length <- length(trie)
  trie_add(trie, "baz", TRUE)
  increased_length <- length(trie)
  trie_remove(trie, "baz")

  testthat::expect_true(original_length < increased_length)
  testthat::expect_true(length(trie) == original_length)
})
