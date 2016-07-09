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
#'@examples
#'trie <- trie(keys = c("afford", "affair", "available", "binary", "bind", "blind"),
#'                    values = c("afford", "affair", "available", "binary", "bind", "blind"))
#'longest_match(trie, "binder")
#'
#'@seealso \code{\link{prefix_match}} and \code{\link{greedy_match}}
#'for prefix and greedy matching, respectively.
#'
#'@export
longest_match <- function(trie, to_match){
  stopifnot("trie" %in% class(trie))
  UseMethod("longest_match", trie)
}

#'@export
longest_match.string_trie <- function(trie, to_match){
  return(longest_string(trie, to_match))
}

#'@export
longest_match.integer_trie <- function(trie, to_match){
  return(longest_integer(trie, to_match))
}

#'@export
longest_match.numeric_trie <- function(trie, to_match){
  return(longest_numeric(trie, to_match))
}

#'@export
longest_match.logical_trie <- function(trie, to_match){
  return(longest_logical(trie, to_match))
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
prefix_match <- function(trie, to_match){
  stopifnot("trie" %in% class(trie))
  UseMethod("prefix_match", trie)
}

#'@export
prefix_match.numeric_trie <- function(trie, to_match){
  return(prefix_numeric(trie, to_match))
}

#'@export
prefix_match.integer_trie <- function(trie, to_match){
  return(prefix_integer(trie, to_match))
}

#'@export
prefix_match.string_trie <- function(trie, to_match){
  return(prefix_string(trie, to_match))
}

#'@export
prefix_match.logical_trie <- function(trie, to_match){
  return(prefix_logical(trie, to_match))
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
#'@return a list, the length of \code{to_match}, with each entry containing any trie values
#'where the \code{to_match} element greedily matches the associated key. In the case that
#'nothing was found, the entry will contain \code{NA}.
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
greedy_match <- function(trie, to_match){
  stopifnot("trie" %in% class(trie))
  UseMethod("greedy_match", trie)
}

#'@export
greedy_match.numeric_trie <- function(trie, to_match){
  return(greedy_numeric(trie, to_match))
}


#'@export
greedy_match.integer_trie <- function(trie, to_match){
  return(greedy_integer(trie, to_match))
}

#'@export
greedy_match.string_trie <- function(trie, to_match){
  return(greedy_string(trie, to_match))
}

#'@export
greedy_match.logical_trie <- function(trie, to_match){
  return(greedy_logical(trie, to_match))
}
