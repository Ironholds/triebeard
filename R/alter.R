#'@title Add or remove trie entries
#'
#'@description \code{trie_add} and \code{trie_remove} allow you to
#'add or remove entries from tries, respectively.
#'
#'@param trie a trie object created with \code{\link{trie}}
#'
#'@param keys a character vector containing the keys of the entries to
#'add (or remove). Entries with NA keys will not be added.
#'
#'@param values an atomic vector, matching the type of the trie, containing
#'the values of the entries to add. Entries with NA values will not be added.
#'
#'@return nothing; the trie is modified in-place
#'
#'@examples
#'trie <- trie("foo", "bar")
#'length(trie)
#'
#'trie_add(trie, "baz", "qux")
#'length(trie)
#'
#'trie_remove(trie, "baz")
#'length(trie)
#'
#'@seealso \code{\link{trie}} for creating tries in the first place.
#'@name alter
#'@rdname alter
#'@export
trie_add <- function(trie, keys, values){
  stopifnot(length(keys) == length(values))
  stopifnot(is.character(keys))
  UseMethod("trie_add", trie)
}

#'@export
trie_add.string_trie <- function(trie, keys, values){
  stopifnot(is.character(values))
  add_trie_string(trie, keys, values)
  return(invisible())
}

#'@export
trie_add.integer_trie <- function(trie, keys, values){
  stopifnot(is.integer(values))
  add_trie_integer(trie, keys, values)
  return(invisible())
}

#'@export
trie_add.numeric_trie <- function(trie, keys, values){
  stopifnot(is.numeric(values))
  add_trie_numeric(trie, keys, values)
  return(invisible())
}

#'@export
trie_add.logical_trie <- function(trie, keys, values){
  stopifnot(is.logical(values))
  add_trie_logical(trie, keys, values)
  return(invisible())
}

#'@rdname alter
#'@export
trie_remove <- function(trie, keys){
  stopifnot(is.character(keys))
  UseMethod("trie_remove", trie)
}

#'@export
trie_remove.string_trie <- function(trie, keys){
  remove_trie_string(trie, keys)
  return(invisible())
}

#'@export
trie_remove.integer_trie <- function(trie, keys){
  remove_trie_integer(trie, keys)
  return(invisible())
}

#'@export
trie_remove.numeric_trie <- function(trie, keys){
  remove_trie_numeric(trie, keys)
  return(invisible())
}

#'@export
trie_remove.logical_trie <- function(trie, keys){
  remove_trie_logical(trie, keys)
  return(invisible())
}
