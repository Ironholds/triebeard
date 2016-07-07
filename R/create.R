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
#'int_trie <- create_trie(keys = "foo", values = 1)
#'
#'# A string trie
#'str_trie <- create_trie(keys = "foo", values = "bar")
#'
#'@export
create_trie <- function(keys, values){
  stopifnot(length(keys) == length(values))
  stopifnot(is.character(keys))
  output <- NULL
  output_classes <- c("trie", NA)

  switch(class(values)[1],
         "numeric" = {
           output <- radix_create_double(keys, values)
           output_classes[2] <- "numeric_trie"
         },
         "integer" = {
           output <- radix_create_int(keys, values)
           output_classes[2] <- "integer_trie"
         },
         "character" = {
           output <- radix_create_str(keys, values)
           output_classes[2] <- "string_trie"
         },
         "logical" = {
           output <- radix_create_bool(keys, values)
           output_classes[2] <- "logical_trie"
         },
         stop("'values' must be a numeric, integer, character or logical vector"))

  class(output) <- c(class(output), output_classes)
  return(output)
}