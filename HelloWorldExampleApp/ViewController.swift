//
//  ViewController.swift
//  HelloWorldExampleApp
//
//  Created by peter.shih on 2019/8/27.
//  Copyright © 2019年 Peteranny. All rights reserved.
//

import UIKit
import HelloWorldSDK
import OpenWrapSDK
import GoogleMobileAds

class ViewController: UIViewController,POBBannerViewDelegate {
    func bannerViewPresentationController() -> UIViewController {
        return self
    }
    
    let DFP_AU_1 = "/15671365/pm_sdk/PMSDK-Demo-App-Banner";
       let OW_ADUNIT_ID_1 = "/15671365/pm_sdk/PMSDK-Demo-App-Banner";
    var hello:HelloWorld?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let label: UILabel = {
            let label = UILabel()
            label.frame.origin = CGPoint(x: 100, y: 100)
//            label.text = HelloWorld().hello(to: "World")
//            label.textColor = HelloWorld().helloColor
            hello = HelloWorld()
            _ = hello?.hello(to: "test")
            label.sizeToFit()
            return label
        }()
        let adSizes = [NSValueFromGADAdSize(kGADAdSizeBanner)]

        let eventHandler = DFPBannerEventHandler(adUnitId: DFP_AU_1, andSizes: adSizes)!
        let bannerView = POBBannerView(publisherId: "156276", profileId: 1165, adUnitId: OW_ADUNIT_ID_1, eventHandler: eventHandler)
        // Set the delegate
        bannerView?.delegate = self
        
        //Add the banner view to your view hierarchy
        addBanner(to: bannerView, with: CGSize(width: 320, height: 50))
        // Load Ad
        bannerView?.loadAd()

        view.addSubview(label)
    }
    
    func addBanner(to bannerView: UIView?, with size: CGSize) {
        bannerView!.frame = CGRect(x: (view.bounds.width - size.width) / 2, y: 250, width: size.width, height: size.height)

        bannerView!.autoresizingMask = [.flexibleLeftMargin, .flexibleRightMargin]
        view.addSubview(bannerView!)
    }
    
}
