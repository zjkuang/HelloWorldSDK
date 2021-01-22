Pod::Spec.new do |s|
  s.name          = "HelloWorldSDK"
  s.version       = "0.0.1"
  s.summary       = "iOS SDK for Hello World"
  s.description   = "iOS SDK for Hello World, including example app"
  s.homepage      = "https://github.com/peteranny/"
  s.license       = "MIT"
  s.author        = "peteranny"
  s.platform      = :ios, "9.0"
  s.swift_version = "4.2"
  s.source        = {
    :git => "https://github.com/peteranny/HelloWorldSDK.git",
    :tag => "#{s.version}"
  }
  s.source_files        = "HelloWorldSDK/**/*.{h,m,swift}"
  s.public_header_files = "HelloWorldSDK/**/*.h"
  
  s.static_framework = true # https://github.com/CocoaPods/CocoaPods/issues/6848#issuecomment-337238159
  s.dependency 'Google-Mobile-Ads-SDK'
  s.dependency 'OpenWrapSDK'
  s.dependency 'OpenWrapEventHandler/DFP'
  s.pod_target_xcconfig = { 'HEADER_SEARCH_PATHS' => '$(SRCROOT)/OpenWrapEventHandler/OpenWrapHandlers/OpenWrapHandlerDFP.framework/Headers' }

end
