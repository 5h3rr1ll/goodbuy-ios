//
//  ViewController.swift
//  goodbuy-ios
//
//  Created by Anthony Sherrill on 05.04.20.
//  Copyright © 2020 Anthony Sherrill. All rights reserved.
//

import UIKit
import ScanditCaptureCore
import ScanditBarcodeCapture


class ViewController: UIViewController {
    let context: DataCaptureContext = {
        let context = DataCaptureContext(licenseKey: "AeSuyV4/QYg7LYs3iyjWyUEPsd8SJWJyH2gmvl1sO3WAfnbMQ2ZKP/J72SV/F52E1Xm5H7NU6gguQyBcBCiGoAYyuHIeWLNQ53oBp3Vza4VYad/JiGg9g8Yv1uALJOvqwT0br0Z35mt9K1gJFMsOce3VLDBPVAd/IJBkpAY4IrGCQBmo+FfGgJ7CoQsHUaOm8MoY27D/5NfzAwdH2nTqNAx8I+7ZeYvLCzVtN8cPM5aobcXrY2LT4fyFQvsfRNE/XD9NzL60d8tCkOHGnSBfsaKTXdrD1WdX1HHHeof/yhygsMxFv+JMXsq/t7CpIYgcjR5AZSaXfEHq2z1EJJdu4PNbgXV2qzZSbOghlo3s8XeQuyhxFp6ulF1RqdSxPMHuyCE3mz7cTpNGTQmgO5iC1iEt9dalcyPfWRj6v83xVEiKFnOQwFlB0aIETMOVag8WRPdhCCyRv37iZqoxX7w7FXhDXSP5xYPYFmNChJUP4Pb2Mf13CwmWZaO4+XqG6YB365jWVGASN8INTwuaNcJEi9i48pQ5HkoEW+8sDn6TZn/r5jC0zTi7skSSbH/cXespuXVJaHAHcyPRRxd49huayV3wHO1ecOUW/I/tgtpmSjQjx9sTgaCtPquXsVPQgdWVlHl4Sd1Kgnottj51qua5mYmMGjW0gC5iJCis8Jxw4M1lL9odB1v9UbEAR31mEnGiuGCFUBMt98vnKoyhWOgJKmSZOauvvmyVesnMDhClTBiSt6m+EzmYTVcC/XScht3Sj4WsKTN533xpnSFriDxyGjejKTazJBzgiSywysaJKwGLug==")
        return context
    }()
    
    let settings: BarcodeCaptureSettings = {
        let settings = BarcodeCaptureSettings()
        settings.set(symbology: .ean8, enabled: true)
        settings.set(symbology: .ean13UPCA, enabled: true)
        return settings
    }()
    
    let cameraSettings = BarcodeCapture.recommendedCameraSettings
//    stores scanned codes, but each code only once
    var codes : [String] = [] {
        didSet{
            print("Codes: \(codes)")
        }
    }
    
    var product : Product! {
        didSet{
            print("Product: \(product!)")
        }
    }
    let button = UIButton(frame: CGRect(x: 100, y: 100, width: 100, height: 50))
//    var product : Product
    
    var barcodeCapture : BarcodeCapture!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        barcodeCapture = BarcodeCapture(context: context, settings: settings)
        barcodeCapture.addListener(self)
        
        let camera = Camera.default
        camera?.apply(cameraSettings)
        self.context.setFrameSource(camera)
        camera?.switch(toDesiredState: .on)
                
        let captureView = DataCaptureView(context: context, frame: view.bounds)
        captureView.context = context
        captureView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        view.addSubview(captureView)
        let overlay = BarcodeCaptureOverlay(barcodeCapture: barcodeCapture, view: captureView)
        overlay.shouldShowScanAreaGuides = true
        captureView.addOverlay(overlay)
        
        button.backgroundColor = .red
        button.setTitle("Done", for: .normal)
        button.addTarget(self, action: #selector(buttonAction), for: .touchUpInside)
        
        self.view.addSubview(button)
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "ModalSingleProductView" {
            guard let singleProductView = segue.destination as? SingleProductViewController else { return }
            singleProductView.product = self.product
        }
    }
    
    
    @objc func buttonAction(sender: UIButton!) {
        callBackEnd(codes[0], onCompletion: { [weak self] product in
            self?.product = product
            DispatchQueue.main.async {
                self?.performSegue(withIdentifier: "ModalSingleProductView", sender: nil)
            }
        })
    }
    
    
    func callBackEnd(_ code: String, onCompletion: @escaping ((Product) -> Void)) {
        let urlString = "http://192.168.178.80:8000/products/\(codes[0])/"
        if let url = URL(string: urlString) {
            URLSession.shared.dataTask(with: url) {data, res, err in
                if let data = data {
                    let decoder = JSONDecoder()
                    if let product = try? decoder.decode(Product.self, from: data) {
                        onCompletion(product)
                    }
                }
            }.resume()
            print("Finished")
        }
    }
}

extension ViewController: BarcodeCaptureListener {
    func barcodeCapture(_ barcodeCapture: BarcodeCapture,
                   didScanIn session: BarcodeCaptureSession,
                   frameData: FrameData) {
        let recognizedBarcodes = session.newlyRecognizedBarcodes
        barcodeCapture.isEnabled = false
        for barcode in recognizedBarcodes {
            // Do something with the barcode.
            print("Barcode: ", barcode.data!)
            if codes.contains(barcode.data!) == false {
                codes.append(barcode.data!)
            }
        }
    }
}
