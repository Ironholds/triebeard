#'@title Find the longest match in a trie
#'@description boop
#'
#'@examples
#'trie <- create_trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
#'                    values = c(1, 2, 3, 4, 5, 6))
#'longest_match(trie, "binder")
#'rm(trie)
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