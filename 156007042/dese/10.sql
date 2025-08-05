SELECT s.name, e.per_pupil_expenditure FROM schools s
JOIN expenditures e ON s.id = e.id
WHERE s.type = 'Public School'
ORDER BY e.per_pupil_expenditure DESC
LIMIT 10;
