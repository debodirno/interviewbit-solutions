/*

Write a SQL Query to find the movie_title and name of director (first and last names combined) who directed a movie that casted a role as ‘SeanMaguire’.

Output Schema:

director_name,movie_title

*/

SELECT CONCAT(d.director_first_name, d.director_last_name) as director_name, m.movie_title
FROM movies m
    INNER JOIN movies_directors md
        ON m.movie_id = md.movie_id
    INNER JOIN directors d
        ON d.director_id = md.director_id
    INNER JOIN movies_cast mc
        ON mc.movie_id = m.movie_id
        AND mc.role = "SeanMaguire";
