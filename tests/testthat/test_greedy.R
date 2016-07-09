testthat::context("Test that greedy-matching works")

testthat::test_that("greedy matching works for string tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = c("afford", "affair", "available", "binary", "bind", "blind"))
  output <- greedy_match(trie, "avoid")
  testthat::expect_equal(length(output), 1)
  testthat::expect_true(is.list(output))
  testthat::expect_true(all(output[[1]] == "available"))
})

testthat::test_that("greedy matching works for integer tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = c(1, 2, 3, 4, 5, 6))
  output <- greedy_match(trie, "avoid")
  testthat::expect_equal(length(output), 1)
  testthat::expect_true(is.list(output))
  testthat::expect_true(all(output[[1]] == 3))
})

testthat::test_that("greedy matching works for numeric tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = as.numeric(c(1, 2, 3, 4, 5, 6)))
  output <- greedy_match(trie, "avoid")
  testthat::expect_equal(length(output), 1)
  testthat::expect_true(is.list(output))
  testthat::expect_true(all(output[[1]] == 3))
})

testthat::test_that("greedy matching works for logical tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = c(FALSE, FALSE, TRUE, FALSE, TRUE, TRUE))
  output <- greedy_match(trie, "avoid")
  testthat::expect_equal(length(output), 1)
  testthat::expect_true(is.list(output))
  testthat::expect_true(output[[1]])
})

testthat::test_that("greedy matching objects to non-trie objects", {
  expect_error(greedy_match("foo", "bar"))
})