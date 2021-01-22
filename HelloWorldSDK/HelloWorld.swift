//
//  HelloWorld.swift
//  HelloWorldSDK
//
//  Created by peter.shih on 2019/8/26.
//  Copyright © 2019年 Peteranny. All rights reserved.
//
import OpenWrapSDK

public class HelloWorld:NSObject, POBInterstitialDelegate {
    let greet = "Hello"

    let dfpAdUnit = "/15671365/pm_sdk/PMSDK-Demo-App-Interstitial"
    let owAdUnit  = "/15671365/pm_sdk/PMSDK-Demo-App-Interstitial"
    let pubId = "156276"
    let profileId : NSNumber = 1165
    var interstitial: POBInterstitial?

    public override init() {
//        GADBannerView(adSize: GADAdSize(size: CGSize.init(width: 320, height: 50), flags: 1))
    }

    public func hello(to whom: String) -> String {
        
        let eventHandler = DFPInterstitialEventHandler(adUnitId: dfpAdUnit)
        // Create an interstitial object
        interstitial = POBInterstitial(publisherId: pubId, profileId: profileId, adUnitId: owAdUnit, eventHandler: eventHandler!)
        // Set the delegate
        interstitial?.delegate = self
        interstitial?.loadAd()
        
        return "\(greet) \(whom)"
    }
    
    public var helloColor: UIColor? {
        if #available(iOS 11.0, *) {
            return UIColor(named: "HelloColor", in: Bundle(for: HelloWorld.self), compatibleWith: nil)
        } else {
            return nil
        }
    }
    
   public func interstitialDidReceiveAd(_ interstitial: POBInterstitial) {
        print("Interstitial : Ad Received")
        if (interstitial.isReady) {
            // Show interstitial ad
            let viewController = UIApplication.shared.windows.first!.rootViewController!
            interstitial.show(from: viewController)
        }
    }
    
}
