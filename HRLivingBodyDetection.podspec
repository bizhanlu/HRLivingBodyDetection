#
# Be sure to run `pod lib lint HRLivingBodyDetection.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'HRLivingBodyDetection'
  s.version          = '1.0.0'
  s.summary          = 'A short description of HRLivingBodyDetection.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/bizhanlu/HRLivingBodyDetection'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { '993009844@qq.com' => '993009844@qq.com' }
  s.source           = { :git => 'https://github.com/bizhanlu/HRLivingBodyDetection.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
  s.requires_arc = true
  s.frameworks = 'UIKit', 'MapKit','SystemConfiguration','CoreMotion','CoreMedia','AVFoundation'
  
  s.subspec 'GHSdkLib' do |gh|
    gh.libraries = 'c++'
    gh.vendored_frameworks = 'HRLivingBodyDetection/Frameworks/*FaceDetector.framework'
    gh.resources ='HRLivingBodyDetection/Resources/BHFace_Resource.bundle'
   
    gh.dependency 'Toast'
    gh.dependency 'Masonry'
  end

  s.subspec 'ZHSdkLib' do |zh|
    zh.vendored_frameworks = 'HRLivingBodyDetection/Frameworks/MGFaceID*.framework'
    zh.resources ='HRLivingBodyDetection/Resources/MGFaceIDLiveCustomDetect.bundle'
  end

end
