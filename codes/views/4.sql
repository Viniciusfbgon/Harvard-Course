SELECT COUNT(*) AS eastern_capital_prints
FROM views
WHERE artist = 'Hiroshige' AND (
    english_title LIKE '%Eastern Capital%' OR
    english_title LIKE '%Edo%'
);
