FUNCTION GetAQIClass(pm)
    IF pm <= 50 THEN
        RETURN "Сайн"
    ELSE IF pm <= 100 THEN
        RETURN "Дунд зэрэг"
    ELSE IF pm <= 150 THEN
        RETURN "Сөрөг нөлөөтэй"
    ELSE IF pm <= 200 THEN
        RETURN "Муу"
    ELSE
        RETURN "Аюултай"
    END IF
END FUNCTION
START
    sum = 0
    mediumDays = 0

    FOR i = 1 TO 7
        DO
            INPUT pm[i]
            IF pm[i] < 0 OR pm[i] > 500 THEN
                PRINT "Error: Value must be between 0 and 500!"
            END IF
        WHILE pm[i] < 0 OR pm[i] > 500

        sum = sum + pm[i]
        IF pm[i] > 50 AND pm[i] <= 100 THEN
            mediumDays = mediumDays + 1
        END IF
        sortedPm[i] = pm[i]
        sortedDay[i] = i
    END FOR

    avg = sum / 7

    PRINT table header: "Day | PM2.5 | Category"
    FOR i = 1 TO 7
        class = CALL GetAQIClass(pm[i])
        PRINT i, pm[i], class
    END FOR

    PRINT "Average PM2.5: ", avg
    PRINT "Moderate days: ", mediumDays

    // Sort from largest to smallest (swap the day number together with the value)
    FOR i = 1 TO 6
        FOR j = i + 1 TO 7
            IF sortedPm[i] < sortedPm[j] THEN
                SWAP sortedPm[i] and sortedPm[j]
                SWAP sortedDay[i] and sortedDay[j]
            END IF
        END FOR
    END FOR

    PRINT "3 most polluted days"
    FOR i = 1 TO 3
        PRINT i, sortedDay[i], sortedPm[i]
    END FOR
END
