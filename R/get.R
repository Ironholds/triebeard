#'@title Trie Getters
#'@description "Getters" for the data stored in a trie object. \code{get_keys}
#' gets the keys, \code{get_values} gets the values.
#'
#'@param trie A trie object, created with \code{\link{trie}}.
#'
#'@return An atomic vector of keys or values stored in the trie.
#'
#'@name getters
#'@rdname getters
NULL

#'@rdname getters
#'@export
get_keys <- function(trie){
  stopifnot("trie" %in% class(trie))
  UseMethod("get_keys", trie)
}

#'@rdname getters
#'@export
get_values <- function(trie){
  stopifnot("trie" %in% class(trie))
  UseMethod("get_values", trie)
}

#'@export
get_keys.string_trie <- function(trie){
  return(get_keys_string(trie))
}

#'@export
get_keys.integer_trie <- function(trie){
  return(get_keys_integer(trie))
}

#'@export
get_keys.numeric_trie <- function(trie){
  return(get_keys_numeric(trie))
}

#'@export
get_keys.logical_trie <- function(trie){
  return(get_keys_logical(trie))
}

#'@export
get_values.string_trie <- function(trie){
  return(get_values_string(trie))
}

#'@export
get_values.integer_trie <- function(trie){
  return(get_values_integer(trie))
}

#'@export
get_values.numeric_trie <- function(trie){
  return(get_values_numeric(trie))
}

#'@export
get_values.logical_trie <- function(trie){
  return(get_values_logical(trie))
}
