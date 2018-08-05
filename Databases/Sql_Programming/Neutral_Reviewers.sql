/*
Write a SQL Query to find the name of all reviewers who have rated their ratings with a NULL value.

Output Schema : 

reviewer_name
*/

SELECT DISTINCT r.reviewer_name 
FROM   reviewers r 
    INNER JOIN ratings r 
        ON r.reviewer_id = ra.reviewer_id 
WHERE  ra.reviewer_stars IS NULL;
