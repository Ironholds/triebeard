#'@title Create a Trie
#'@description \code{create_trie} creates a trie (a key-value store optimised
#'for matching) out of a provided character vector of keys, and a numeric,
#'character, logical or integer vector of values (both the same length).
#'
#'@param keys a character vector containing the keys for the trie.
#'
#'@param values an atomic vector of any type, containing the values to pair with
#'\code{keys}. Must be the same length as \code{keys}.
#'
#'@return a `trie` object.
#'
#'@seealso \code{\link{trie_add}} and \code{\link{trie_remove}} for adding to and removing
#'from tries after their creation, and \code{\link{longest_match}} and other match functions
#'for matching values against the keys of a created trie.
#'
#'@examples
#'# An integer trie
#'int_trie <- trie(keys = "foo", values = 1)
#'
#'# A string trie
#'str_trie <- trie(keys = "foo", values = "bar")
#'
#'@export
trie <- function(keys, values){
  stopifnot(length(keys) == length(values))
  stopifnot(is.character(keys))
  output <- NULL
  output_classes <- c("trie", NA)

  switch(class(values)[1],
         "character" = {
           output <- radix_create_string(keys, values)
           output_classes[2] <- "string_trie"
         },
         "integer" = {
           output <- radix_create_integer(keys, values)
           output_classes[2] <- "integer_trie"
         },
         "numeric" = {
           output <- radix_create_numeric(keys, values)
           output_classes[2] <- "numeric_trie"
         },
         "logical" = {
           output <- radix_create_logical(keys, values)
           output_classes[2] <- "logical_trie"
         },
         stop("'values' must be a numeric, integer, character or logical vector"))

  class(output) <- c(class(output), output_classes)
  return(output)
}