#'@title Find the longest match in a trie
#'@description \code{longest_match} accepts a trie and a character vector
#'and returns the value associated with whichever key had the \emph{longest match}
#'to each entry in the character vector. A trie of "binary" and "bind", for example,
#'with an entry-to-compare of "binder", will match to "bind".
#'
#'@param trie a trie object, created with \code{\link{trie}}
#'
#'@param to_match a character vector containing the strings to match against the
#'trie's keys.
#'
#'@param include_keys a logical value indicating whether to include the keys in the
#'returned results or not. If TRUE (\emph{not} the default) the returned object will
#'be a data.frame, rather than a vector.
#'
#'@examples
#'trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
#'                    values = c("afford", "affair", "available", "binary", "bind", "blind"))
#'longest_match(trie, "binder")
#'
#'@seealso \code{\link{prefix_match}} and \code{\link{greedy_match}}
#'for prefix and greedy matching, respectively.
#'
#'@export
longest_match <- function(trie, to_match, include_keys = FALSE){
  stopifnot("trie" %in% class(trie))
  stopifnot(!is.na(include_keys))
  UseMethod("longest_match", trie)
}

#'@export
longest_match.string_trie <- function(trie, to_match, include_keys = FALSE){
  return(longest_string(trie, to_match, include_keys))
}

#'@export
longest_match.integer_trie <- function(trie, to_match, include_keys = FALSE){
  return(longest_integer(trie, to_match, include_keys))
}

#'@export
longest_match.numeric_trie <- function(trie, to_match, include_keys = FALSE){
  return(longest_numeric(trie, to_match, include_keys))
}

#'@export
longest_match.logical_trie <- function(trie, to_match, include_keys = FALSE){
  return(longest_logical(trie, to_match, include_keys))
}

#'@title Find the prefix matches in a trie
#'@description \code{prefix_match} accepts a trie and a character vector
#'and returns the values associated with any key that has a particular
#'character vector entry as a prefix (see the examples).
#'
#'@param trie a trie object, created with \code{\link{trie}}
#'
#'@param to_match a character vector containing the strings to check against the
#'trie's keys.
#'
#'@param include_keys a logical value indicating whether to include the keys in the
#'returned results or not. If TRUE (\emph{not} the default) the returned object will
#'be a list of data.frames, rather than of vector.
#'
#'@return a list, the length of \code{to_match}, with each entry containing any trie values
#'where the \code{to_match} element was a prefix of the associated key. In the case that
#'nothing was found, the entry will contain \code{NA}.
#'
#'@examples
#'trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
#'                    values = c("afford", "affair", "available", "binary", "bind", "blind"))
#'prefix_match(trie, "aff")
#'
#'@seealso \code{\link{longest_match}} and \code{\link{greedy_match}}
#'for longest and greedy matching, respectively.
#'
#'@export
prefix_match <- function(trie, to_match, include_keys = FALSE){
  stopifnot("trie" %in% class(trie))
  stopifnot(!is.na(include_keys))
  UseMethod("prefix_match", trie)
}

#'@export
prefix_match.numeric_trie <- function(trie, to_match, include_keys = FALSE){
  return(prefix_numeric(trie, to_match, include_keys))
}

#'@export
prefix_match.integer_trie <- function(trie, to_match, include_keys = FALSE){
  return(prefix_integer(trie, to_match, include_keys))
}

#'@export
prefix_match.string_trie <- function(trie, to_match, include_keys = FALSE){
  return(prefix_string(trie, to_match, include_keys))
}

#'@export
prefix_match.logical_trie <- function(trie, to_match, include_keys = FALSE){
  return(prefix_logical(trie, to_match, include_keys))
}

#'@title Greedily match against a tree
#'@description \code{greedy_match} accepts a trie and a character vector
#'and returns the values associated with any key that is "greedily" (read: fuzzily)
#'matched against one of the character vector entries.
#'
#'@param trie a trie object, created with \code{\link{trie}}
#'
#'@param to_match a character vector containing the strings to check against the
#'trie's keys.
#'
#'@param include_keys a logical value indicating whether to include the keys in the
#'returned results or not. If TRUE (\emph{not} the default) the returned object will
#'be a list of data.frames, rather than of vectors.
#'
#'@return a list, the length of \code{to_match}, with each entry containing any trie values
#'where the \code{to_match} element greedily matches the associated key. In the case that
#'nothing was found, the entry will contain \code{NA}. In the case that \code{include_keys}
#'is TRUE, the matching keys will also be included
#'
#'@examples
#'trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
#'                    values = c("afford", "affair", "available", "binary", "bind", "blind"))
#'greedy_match(trie, c("avoid", "bring", "attack"))
#'
#'@seealso \code{\link{longest_match}} and \code{\link{prefix_match}}
#'for longest and prefix matching, respectively.
#'
#'@export
greedy_match <- function(trie, to_match, include_keys = FALSE){
  stopifnot("trie" %in% class(trie))
  stopifnot(!is.na(include_keys))
  UseMethod("greedy_match", trie)
}

#'@export
greedy_match.numeric_trie <- function(trie, to_match, include_keys = FALSE){
  return(greedy_numeric(trie, to_match, include_keys))
}


#'@export
greedy_match.integer_trie <- function(trie, to_match, include_keys = FALSE){
  return(greedy_integer(trie, to_match, include_keys))
}

#'@export
greedy_match.string_trie <- function(trie, to_match, include_keys = FALSE){
  return(greedy_string(trie, to_match, include_keys))
}

#'@export
greedy_match.logical_trie <- function(trie, to_match, include_keys = FALSE){
  return(greedy_logical(trie, to_match, include_keys))
}
