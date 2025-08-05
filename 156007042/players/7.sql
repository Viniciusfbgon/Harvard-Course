SELECT COUNT(*) AS opposite_handed_players
FROM players
WHERE (bats = 'R' AND throws = 'L')
   OR (bats = 'L' AND throws = 'R')
   OR (bats = 'B' AND throws IN ('L', 'R'));
