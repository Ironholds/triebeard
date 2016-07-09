#'@export
as.list.trie <- function(x, ...){
  return(list(keys = get_keys(x), values = get_values(x)))
}

#'@export
as.data.frame.trie <- function(x, row.names = NULL, stringsAsFactors = FALSE){

  output <- data.frame(keys = get_keys(x),
                       values = get_values(x),
                       stringsAsFactors = stringsAsFactors)
  if(!is.null(row.names)){
    rownames(output) <- row.names
  }
  return(output)
}

#'@export
as.vector.trie <- function(x, ...){
  output <- get_values(x)
  names(output) <- get_keys(x)
  return(output)
}