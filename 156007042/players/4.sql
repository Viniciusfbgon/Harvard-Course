SELECT first_name, last_name FROM players
WHERE birth_country NOT IN ('United States', 'USA')
ORDER BY first_name ASC, last_name ASC;
