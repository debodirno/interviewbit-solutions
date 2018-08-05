/*

Write a SQL Query to find those lowest duration movies along with the year, director’s name(first and last name combined), actor’s name(first and last name combined) and his/her role in that production.

Output Schema:

movie_title,movie_year,director_name,actor_name,role

*/

SELECT m.movie_title, m.movie_year,
CONCAT(d.director_first_name, d.director_last_name) as director_name,
CONCAT(a.actor_first_name, a.actor_last_name) as actor_name, mc.role
FROM movies m
    INNER JOIN movies_directors md
        ON md.movie_id = m.movie_id
    INNER JOIN directors d
        ON md.director_id = d.director_id
    INNER JOIN movies_cast mc
        ON mc.movie_id = m.movie_id
    INNER JOIN actors a
        ON a.actor_id = mc.actor_id
WHERE m.movie_time IN (SELECT MIN(m2.movie_time) FROM movies m2);
