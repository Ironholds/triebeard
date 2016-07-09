testthat::context("Test that prefix-matching works")

testthat::test_that("prefix matching works for string tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = c("afford", "affair", "available", "binary", "bind", "blind"))
  output <- prefix_match(trie, "bin")
  testthat::expect_equal(length(output), 1)
  testthat::expect_true(is.list(output))
  testthat::expect_true(all(output[[1]] == c("binary", "bind")))
})

testthat::test_that("prefix matching works for integer tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = c(1, 2, 3, 4, 5, 6))
  output <- prefix_match(trie, "bin")
  testthat::expect_equal(length(output), 1)
  testthat::expect_true(is.list(output))
  testthat::expect_true(all(output[[1]] == c(4, 5)))
})

testthat::test_that("prefix matching works for numeric tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = as.numeric(c(1, 2, 3, 4, 5, 6)))
  output <- prefix_match(trie, "bin")
  testthat::expect_equal(length(output), 1)
  testthat::expect_true(is.list(output))
  testthat::expect_true(all(output[[1]] == c(4, 5)))
})

testthat::test_that("prefix matching works for logical tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = c(FALSE, FALSE, TRUE, FALSE, TRUE, TRUE))
  output <- prefix_match(trie, "bin")
  testthat::expect_equal(length(output), 1)
  testthat::expect_true(is.list(output))
  testthat::expect_true(all(output[[1]] == c(FALSE, TRUE)))
})

testthat::test_that("prefix matching objects to non-trie objects", {
  expect_error(prefix_match("foo", "bar"))
})

testthat::test_that("prefix matching produces NAs with impossibilities", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = c(FALSE, FALSE, TRUE, FALSE, TRUE, TRUE))
  output <- prefix_match(trie, "bingo")
  testthat::expect_equal(length(output), 1)
  testthat::expect_true(is.list(output))
  testthat::expect_true(is.na(output[[1]]))
})
