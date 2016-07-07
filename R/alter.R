trie_add <- function(trie, keys, values){
  stopifnot(length(keys) == length(values))
  stopifnot(is.character(keys))
  UseMethod("trie_add", trie)
}

trie_add.string_trie <- function(trie, keys, values){
  stopifnot(is.character(values))
  return(add_trie_str(trie, keys, values))
}

trie_add.numeric_trie <- function(trie, keys, values){
  stopifnot(is.numeric(values))
  return(add_trie_double(trie, keys, values))
}

trie_add.integer_trie <- function(trie, keys, values){
  stopifnot(is.integer(values))
  return(add_trie_int(trie, keys, values))
}

trie_add.logical_trie <- function(trie, keys, values){
  stopifnot(is.logical(values))
  return(add_trie_bool(trie, keys, values))
}

trie_remove <- function(trie, keys){
  stopifnot(is.character(keys))
  UseMethod("trie_remove", trie)
}

trie_remove.string_trie <- function(trie, keys){
  return(remove_trie_str(trie, keys))
}

trie_remove.numeric_trie <- function(trie, keys){
  return(remove_trie_double(trie, keys))
}

trie_remove.integer_trie <- function(trie, keys){
  return(remove_trie_int(trie, keys))
}

trie_remove.logical_trie <- function(trie, keys){
  return(remove_trie_bool(trie, keys))
}