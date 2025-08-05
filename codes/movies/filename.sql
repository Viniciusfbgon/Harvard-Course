SELECT title FROM movies
WHERE year = 2008;

SELECT birth FROM people WHERE name = 'Emma Stone';

SELECT title FROM movies
WHERE year >= 2018
ORDER BY title ASC;


SELECT COUNT(*) FROM ratings
WHERE rating = 10.0;

SELECT title, year FROM movies
WHERE title LIKE 'Harry Potter%'
ORDER BY year ASC;

SELECT AVG(rating) from ratings
WHERE movie_id IN (SELECT id FROM movies WHERE year = 2012);

SELECT m.title, r.rating FROM movies m
JOIN ratings r ON m.id = r.movie_id
WHERE m. year = 2010
ORDER BY r.rating DESC, m.title ASC;

SELECT people.name FROM people , stars, movies
WHERE people.id = stars.person_id AND stars.movie_id = movies.id
AND movies.title = 'Toy Story';


SELECT p.name FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
WHERE m.year = 2004
ORDER BY p.birth;


SELECT DISTINCT p.name FROM people p
JOIN directors d ON p.id = d.person_id
JOIN movies m ON d.movie_id = m.id
JOIN ratings r ON m.id = r.movie_id
WHERE r.rating >= 9.0;

SELECT title FROM movies
JOIN ratings ON ratings.movie_id = movies.id
JOIN stars ON stars.movie_id = movies.id
JOIN people ON stars.person_id = people.id
WHERE people.name = "Chadwick Boseman"
ORDER BY ratings.rating DESC
LIMIT 5;

SELECT m.title FRom movies m
JOIN stars s ON m.id = s.movie_id
JOIN people p ON s.person_id = p.id
WHERE p.name IN ('Johnny Depp', 'Helena Bonham Carter')
GROUP BY m.title
HAVING COUNT (DISTINCT p.name) = 2;


SELECT p.name FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
WHERE m.id IN (
    SELECT m.id FROM movies m
    JOIn stars s ON m.id = s.movie_id
    JOIN people p ON s.person_id = p.id
    WHERE p.name = 'Kevin Bacon' AND p.birth = 1958
)   AND p.name != 'Kevin Bacon';


