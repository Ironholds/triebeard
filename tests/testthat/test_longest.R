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

testthat::test_that("Longest matching understands the new include_keys param", {

  trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
               values = c("afford", "affair", "available", "muffin", "bind", "frog"))
  result <- longest_match(trie, "binaryness", TRUE)
  testthat::expect_true(is.data.frame(result))
  testthat::expect_equal(result$match_key, "binary")
  testthat::expect_equal(result$match_value, "muffin")

})
testthat::test_that("Longest matching rejects non-trie objects", {
  expect_error(longest_match("foo", "bar"))
})