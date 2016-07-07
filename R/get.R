#'@title Trie Getters
#'@description "Getters" for the data stored in a trie object. \code{get_keys}
#' gets the keys, \code{get_values} gets the values.
#'
#'@param trie A trie object.
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

#'@rdname getters
#'@export
get_keys.numeric_trie <- function(trie){
  return(get_keys_double(trie))
}

#'@rdname getters
#'@export
get_keys.integer_trie <- function(trie){
  return(get_keys_int(trie))
}

#'@rdname getters
#'@export
get_keys.string_trie <- function(trie){
  return(get_keys_str(trie))
}

#'@rdname getters
#'@export
get_keys.bool_trie <- function(trie){
  return(get_keys_bool(trie))
}

#'@rdname getters
#'@export
get_values.numeric_trie <- function(trie){
  return(get_values_double(trie))
}

#'@rdname getters
#'@export
get_values.integer_trie <- function(trie){
  return(get_values_int(trie))
}

#'@rdname getters
#'@export
get_values.string_trie <- function(trie){
  return(get_values_str(trie))
}

#'@rdname getters
#'@export
get_values.bool_trie <- function(trie){
  return(get_values_bool(trie))
}
