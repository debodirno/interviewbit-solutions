/*

Write a SQL Query to find the name of those movies where one or more actors acted in two or more movies.

Output Schema:

movie_title

*/


SELECT mo.movie_title
FROM movies mo
    INNER JOIN movies_cast mc
        ON mc.movie_id = mo.movie_id
        AND mc.actor_id IN (
            SELECT mc2.actor_id
            FROM movies_cast mc2
            GROUP BY mc2.actor_id
            HAVING COUNT(mc2.actor_id) > 1
        );

