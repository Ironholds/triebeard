#'@export
as.list.string_trie <- function(x, ...){
  return(trie_to_list_string(x))
}

#'@export
as.list.integer_trie <- function(x, ...){
  return(trie_to_list_integer(x))
}

#'@export
as.list.numeric_trie <- function(x, ...){
  return(trie_to_list_numeric(x))
}

#'@export
as.list.logical_trie <- function(x, ...){
  return(trie_to_list_logical(x))
}
