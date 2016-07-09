#'@export
as.list.trie <- function(x, ...){
  return(list(keys = get_keys(x), values = get_values(x)))
}

#'@export
as.data.frame.trie <- function(x, row.names = NULL, optional = FALSE,
                               stringsAsFactors = FALSE, ...){

  output <- data.frame(keys = get_keys(x),
                       values = get_values(x),
                       stringsAsFactors = stringsAsFactors,
                       ...)
  if(!is.null(row.names)){
    rownames(output) <- row.names
  }
  return(output)
}