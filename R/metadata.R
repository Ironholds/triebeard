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
  obj_len <- length(object)
  type <- class(object)[3]
  cat(paste0(type, "\n"))
  
  if (type == "string_trie")
    trie_str_string(object)
  else if (type == "integer_trie")
    trie_str_integer(object)
  else if (type == "numeric_trie")
    trie_str_numeric(object)
  else if (type == "logical_trie")
    trie_str_logical(object)
  
  return(invisible())
}

#'@export
print.trie <- function(x, ...){
  cat("A", class(x)[3], "object with", length(x), "entries\n")
}
