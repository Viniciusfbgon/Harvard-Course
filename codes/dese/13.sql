--qual cidade tem a maior porcentagem de estudantes que sairam antes de formar, com
--nome e a porcentagem

SELECT s.name, g.dropped FROM schools s
JOIN graduation_rates g ON s.id = g.school_id
ORDER BY g.dropped DESC
LIMIT 1;

