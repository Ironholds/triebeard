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
  cat(paste0(
    class(object)[3],
    ifelse(obj_len > 1, paste0(" [1:",obj_len, "] "), " "),
    "f"
  ))
  return(invisible())
}
