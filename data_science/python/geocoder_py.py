from pickle import FALSE
from geocoder.google import GoogleGeocoderClient
geocoder = GoogleGeocoderClient(False)
result = geocoder.Geocode("Paramakudi")
print(result)