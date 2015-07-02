//
//  Steps.h
//  Bike Stations
//
//  Created by Ken Woo on 2015-07-02.
//  Copyright (c) 2015 Lighthouse Labs. All rights reserved.
//

#ifndef Bike_Stations_Steps_h
#define Bike_Stations_Steps_h

// 1: Setup our storyboard, import the MapKit framework in Build Phases -> Link Libraries with Binary

// 2: Create a property to store a CLLocationManager. Alloc/init it and then setup delegate.

// 3: Check the authorizationStatus, and request when in use permission. Make sure to setup NSLocationWhenInUseUsageDescription in Info.plist

// 4: Tell locationManager to startUpdatingLocation. Setup an initial region if we haven't done so

// 5: Add a gpx file for a position, or a list of positions to test in simulator. Setup a default location in the scheme if you want.

/*
 Examples:
 <wpt lat="43.647180" lon="-79.403403">
    <name>Lighthouse Labs: Toronto</name>
 </wpt>
 
 or 
 
 <wpt lat="43.647197" lon="-79.403993">
    <name>Queen And Bathurst</name>
 </wpt>
 <wpt lat="43.652416" lon="-79.379265">
    <name>Queen And Yonge</name>
 </wpt>
 <wpt lat="43.779758" lon="-79.415569">
    <name>Finch And Yonge</name>
 </wpt>
 <wpt lat="43.652416" lon="-79.379265">
    <name>Queen And Yonge</name>
 </wpt>
 <wpt lat="43.647197" lon="-79.403993">
    <name>Queen And Bathurst</name>
 </wpt>
 */


/* These next few are all optional, depends on what we want to cover in class */

// 6: Add a button to center the map to the user's current location. Open settings if permission is denied.

/*
 Code to open settings:
 UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Denied" message:@"Please enable us to stalk where you are" preferredStyle:UIAlertControllerStyleAlert];
 
 UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:nil];
 [alertController addAction:cancelAction];
 
 UIAlertAction *openAction = [UIAlertAction actionWithTitle:@"Open Settings" style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
 
     NSURL *settingsURL = [NSURL URLWithString:UIApplicationOpenSettingsURLString];
     if (settingsURL) {
         [[UIApplication sharedApplication] openURL:settingsURL];
     }
 }];
 [alertController addAction:openAction];
 [self presentViewController:alertController animated:YES completion:nil];
 
 */

// 7: Add a bunch of bike station annotations by loading a json file.

/*
 Code to parse JSON file:
 NSString *jsonPath =[[NSBundle mainBundle] pathForResource:@"bikeStations" ofType:@"json"];
 NSData *jsonData = [NSData dataWithContentsOfFile:jsonPath];
 
 NSError *error = nil;
 NSDictionary *stationDict = [NSJSONSerialization JSONObjectWithData:jsonData options:NSJSONReadingMutableContainers error:&error];
 if (!error) {
 NSArray *stations = stationDict[@"stations"][@"station"];
 for (NSDictionary *station in stations) {
 
 MKPointAnnotation *marker = [[MKPointAnnotation alloc] init];
 
 marker.coordinate = CLLocationCoordinate2DMake([station[@"lat"] doubleValue], [station[@"long"] doubleValue]);
 marker.title = station[@"name"];
 marker.subtitle = station[@"terminalName"];
 
 [self.mapView addAnnotation:marker];
 
 }
 }
 */

// 7.1: Make custom objects that conform to MKAnnotation to display markers instead. These will allow us to store extra information

// 7.2: Implement delegate method to set the image of the annotation

// 8: Use CLGeoCoder example to get address from location, and location from addressString

// 9: Use MKLocalSearch for a map lookup of something

#endif
