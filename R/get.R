#'@export
get_keys <- function(trie){
  stopifnot("trie" %in% class(trie))
  UseMethod("get_keys", trie)
}

#'@export
get_values <- function(trie){
  stopifnot("trie" %in% class(trie))
  UseMethod("get_values", trie)
}

#'@export
get_keys.numeric_trie <- function(x){
  return(get_keys_double(x))
}

#'@export
get_keys.integer_trie <- function(x){
  return(get_keys_int(x))
}

#'@export
get_keys.string_trie <- function(x){
  return(get_keys_str(x))
}

#'@export
get_keys.bool_trie <- function(x){
  return(get_keys_bool(x))
}

#'@export
get_values.numeric_trie <- function(x){
  return(get_values_double(x))
}

#'@export
get_values.integer_trie <- function(x){
  return(get_values_int(x))
}

#'@export
get_values.string_trie <- function(x){
  return(get_values_str(x))
}

#'@export
get_values.bool_trie <- function(x){
  return(get_values_bool(x))
}