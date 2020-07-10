//
//  SingleProductViewController.swift
//  goodbuy-ios
//
//  Created by Anthony Sherrill on 25.06.20.
//  Copyright © 2020 Anthony Sherrill. All rights reserved.
//

import Foundation
import UIKit

class SingleProductViewController: UIViewController {
    
    var product : Product!
    
    @IBOutlet weak var productNameLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        productNameLabel.text = product.name
        productNameLabel.sizeToFit()
    }
}
