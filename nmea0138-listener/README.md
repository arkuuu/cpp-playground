# NMEA0138 listener

NMEA0138 is a data protocol used for communication between navigation devices and sensors on pleasure boats.
It's older but still in good use as the newer version, NMEA2000, is way more complex to decode.

The program creates a UDP connection to an NMEA0138 multiplexer, which sends out data.
To simulate this multiplexer while not on board, I use [transmitterdan/VDRplayer](https://github.com/transmitterdan/VDRplayer).
The intention is to read and decode the data to show the actual navigation data like position, course, depth etc.

It is still a work in progress. As of now, it only shows the received NMEA sentences without proper parsing. I know there are a lot of fully grown NMEA0138 libraries out there. But I want to do this on my own to learn.

## Example output

```plain
Receiving NMEA data...

$GPRMC,092235.00,A,5759.12557,N,01144.37962,E,5.100,37.05,200715,,,A*56
talkerId: GP
dataType: RMC
data[0]: 092235.00
data[1]: A
data[2]: 5759.12557
data[3]: N
data[4]: 01144.37962
data[5]: E
data[6]: 5.100
data[7]: 37.05
data[8]: 200715
data[9]:
data[10]:
data[11]: A
data[12]:
checksum: 56

$IIHDG,31.0,0,E,0.0,E*65
talkerId: II
dataType: HDG
data[0]: 31.0
data[1]: 0
data[2]: E
data[3]: 0.0
data[4]: E
data[5]:
checksum: 65

$IIDPT,15.5,0.4,100.0*76
talkerId: II
dataType: DPT
data[0]: 15.5
data[1]: 0.4
data[2]: 100.0
data[3]:
checksum: 76
```

## References

- <https://actisense.com/wp-content/uploads/2021/01/Everything-you-need-to-know-about-NMEA-0183-1.pdf>
- <http://www.nmea.de/nmea0183datensaetze.html>
- <https://gpsd.gitlab.io/gpsd/NMEA.html>
- <https://beej.us/guide/bgnet/html/>
