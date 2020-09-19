SELECT AVG(rating) as AverageRatingFor2012Movies

From ratings JOIN movies ON movies.id = ratings.movie_id

WHERE year = 2012;