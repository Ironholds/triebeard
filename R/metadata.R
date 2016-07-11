#'@export
length.string_trie <- function(x){
  return(radix_len_string(x))
}

#'@export
length.integer_trie <- function(x){
  return(radix_len_integer(x))
}

#'@export
length.numeric_trie <- function(x){
  return(radix_len_numeric(x))
}

#'@export
length.logical_trie <- function(x){
  return(radix_len_logical(x))
}

#'@export
dim.trie <- function(x){
  return(length(x))
}

#'@export
str.trie <- function(object, ...){
  type <- class(object)[3]
  cat(paste0(type, "\n"))

  switch(type,
         "string_trie"  = {trie_str_string(object)},
         "integer_trie" = {trie_str_integer(object)},
         "numeric_trie" = {trie_str_numeric(object)},
         "logical_trie" = {trie_str_logical(object)}
         )

  return(invisible())
}

#'@export
print.trie <- function(x, ...){
  len <- length(x)
  entry_word <- ifelse(len != 1, "entries", "entry")
  cat("A", class(x)[3], "object with", len, entry_word, "\n")
}
