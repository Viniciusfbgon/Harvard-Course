SELECT s.name, e.per_pupil_expenditure, g.graduated FROM districts d
JOIN expenditures e ON d.id = e.district_id
JOIN schools s ON s.district_id = d.id
JOIN graduation_rates g ON s.id = g.school_id
ORDER BY e.per_pupil_expenditure DESC, s.name;
