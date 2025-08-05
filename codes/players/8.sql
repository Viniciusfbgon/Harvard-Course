SELECT ROUND(AVG(height), 1) AS "Average Height", ROUND(AVG(weight), 1) AS "Average Weight" FROM players
WHERE debut >= '2000-01-01' AND height IS NOT NULL AND weight IS NOT NULL;
