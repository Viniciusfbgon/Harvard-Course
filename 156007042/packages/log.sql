
-- *** The Lost Letter ***
SELECT * FROM addresses
WHERE address LIKE "2 Fin%";

SELECT * FROM addresses
WHERE address = "900 Somerville Avenue";

SELECT * FROM scans
WHERE package_id = (
    SELECT id FROM packages
    WHERE from_address_id = (
    SELECT id FROM addresses
    WHERE address = "900 Somerville Avenue"
) AND to_address_id = (
    SELECT id FROM addresses
    WHERE address LIKE "2 Fin%"
)
);

-- *** The Devious Delivery ***
SELECT * FROM packages
WHERE from_address_id IS NULL;

SELECT * FROM scans
WHERE package_id = (
    SELECT id FROM packages
    WHERE from_address_id IS NULL
);

SELECT address_id FROM scans
WHERE package_id = (
    SELECT id FROM packages
    WHERE from_address_id IS NULL
) AND action = 'Drop';

SELECT type FROM addresses
WHERE id = (
    SELECT address_id FROM scans
    WHERE package_id = (
    SELECT id FROM packages
    WHERE from_address_id IS NULL
) AND action = 'Drop'
);

-- *** The Forgotten Gift ***
/*sabe de onde veio,    sabe pra onde tem q ir
109 Tileston Street    728 Maple Place

Qual é o conteúdo do Presente Esquecido?

Quem tem o Presente Esquecido? */

SELECT * FROM addresses
WHERE address = '109 Tileston Street';

SELECT * FROM addresses
WHERE address = '728 Maple Place';

SELECT * FROM packages
WHERE from_address_id = (
    SELECT id FROM addresses
    WHERE address = '109 Tileston Street'
);

SELECT * FROM scans
WHERE package_id = (
    SELECT id FROM packages
    WHERE from_address_id = (
        SELECT id FROM addresses
        WHERE address = '109 Tileston Street'
)
);

SELECT driver_id FROM scans
WHERE package_id = (
    SELECT id FROM packages
    WHERE from_address_id = (
        SELECT id FROM addresses
        WHERE address = '109 Tileston Street'
)
) ORDER BY timestamp DESC LIMIT 1;


SELECT name FROM drivers
WHERE id = (
    SELECT driver_id FROM scans
    WHERE package_id = (
        SELECT id FROM packages
        WHERE from_address_id = (
            SELECT id FROM addresses
            WHERE address = '109 Tileston Street'
)
) ORDER BY timestamp DESC LIMIT 1
);

SELECT d.name FROM drivers d
JOIN scans s ON d.id = s.id
WHERE driver_id = 17;

