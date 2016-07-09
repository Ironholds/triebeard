testthat::context("Test that longest-matching works")

testthat::test_that("Longest matching works for string tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = c("afford", "affair", "available", "binary", "bind", "blind"))
  testthat::expect_equal(longest_match(trie, "binder"), "bind")
})

testthat::test_that("Longest matching works for integer tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = c(1, 2, 3, 4, 5, 6))
  testthat::expect_equal(longest_match(trie, "binder"), 5)
})

testthat::test_that("Longest matching works for numeric tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = as.numeric(c(1, 2, 3, 4, 5, 6)))
  testthat::expect_equal(longest_match(trie, "binder"), 5.0)
})

testthat::test_that("Longest matching works for logical tries", {
  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
                      values = c(FALSE, FALSE, TRUE, FALSE, TRUE, TRUE))
  testthat::expect_true(longest_match(trie, "binder"))
})

testthat::test_that("Longest matching objects to non-trie objects", {
  expect_error(longest_match("foo", "bar"))
})