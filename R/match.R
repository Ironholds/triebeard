#'@title Find the longest match in a trie
#'@description \code{longest_match} accepts a trie and a character vector
#'and returns the value associated with whichever key had the \emph{longest match}
#'to each entry in the character vector. A trie of "binary" and "bind", for example,
#'with an entry-to-compare of "binder", will match to "bind".
#'
#'@param trie a trie object, created with \code{\link{create_trie}}
#'
#'@param to_match a character vector containing the strings to match against the
#'trie's keys.
#'
#'@examples
#'trie <- create_trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
#'                    values = c(1, 2, 3, 4, 5, 6))
#'longest_match(trie, "binder")
#'
#'@export
longest_match <- function(trie, to_match){
  UseMethod("longest_match", trie)
}

#'@export
longest_match.numeric_trie <- function(trie, to_match){
  return(longest_double(trie, to_match))
}

#'@export
longest_match.integer_trie <- function(trie, to_match){
  return(longest_int(trie, to_match))
}

#'@export
longest_match.string_trie <- function(trie, to_match){
  return(longest_str(trie, to_match))
}

#'@export
longest_match.bool_trie <- function(trie, to_match){
  return(longest_bool(trie, to_match))
}


partial_match <- function(trie, match_text){
  UseMethod("partial_match", trie)
}

prefix_match <- function(trie, match_text){
  UseMethod("prefix_match", trie)
}