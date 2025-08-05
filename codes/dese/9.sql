SELECT s.name FROM schools s
JOIN expenditures e ON s.id = e.id
ORDER BY e.pupils
LIMIT 1;
