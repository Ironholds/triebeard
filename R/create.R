create_trie <- function(keys, values){
  stopifnot(length(keys) == length(values))
  stopifnot(is.character(keys))
  output <- NULL
  output_classes <- c("trie", NA)

  switch(class(values)[1],
         "numeric" = {
           output <- radix_create_double(keys, values)
           output_classes[1] <- "numeric_trie"
           break
         },
         "integer" = {
           output <- radix_create_int(keys, values)
           output_classes[1] <- "integer_trie"
           break
         },
         "character" = {
           output <- radix_create_str(keys, values)
           output_classes[1] <- "string_trie"
           break
         },
         "logical" = {
           output <- radix_create_bool(keys, values)
           output_classes[1] <- "logical_trie"
           break
         },
         stop("'values' must be a numeric, integer, character or logical vector"))

  class(output) <- c(class(output), output_classes)
  return(output)
}